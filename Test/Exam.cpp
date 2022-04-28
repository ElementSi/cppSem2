#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class ResultsHolder {
private:
    map<string, unsigned> result_table;
    set<string> students;
    vector<pair<string, unsigned>> result_list;
public:
    /**
     * Добавить в общую таблицу результат экзамена студента.
     * Параметры:
     * - full_name - строка с полным именем студента
     * - mark - оценка (от 1 до 10)
     * (Гарантируется, что совпадений полных имён у разных студентов не бывает.)
     *
     * Если студента с данным именем нет в результатах - добавить его.
     * Если студент с таким именем есть - обновить его результат
     * (потому что апелляции вполне возможны).
     */
    void update(const std::string &full_name, unsigned mark) {
        result_table[full_name] = mark;
        students.insert(full_name);
        result_list.clear();
        copy(
                result_table.begin(),
                result_table.end(),
                inserter(result_list, result_list.begin())
        );
    }

    /**
     * Вывести студентов, отсортировав по именам по алфавиту.
     *
     * Вывод в std::cout.
     *
     * Формат вывода:
     * Alex 7
     * Anastasia 9
     * Anny 5
     * Ivan 10
     * Nikita 8
     */
    void print_students() const {
        for (const auto& stud: result_list) {
            cout << stud.first << " " << stud.second << endl;
        }
    }

    /**
     * Вывести студентов, отсортировав сперва по оценкам по убыванию,
     * а при равных оценках - по именам по алфавиту.
     *
     * Вывод в std::cout.
     *
     * Формат вывода:
     * Ivan 10
     * Anastasia 9
     * Nikita 8
     * Alex 7
     * Anny 5
     */
    void print_standings() const {
        auto copy_result_list = result_list;

        sort(
                copy_result_list.begin(),
                copy_result_list.end(),
                [](const pair<string, unsigned>& stud1, const pair<string, unsigned>& stud2) {
                    if (stud1.second != stud2.second) {
                        return stud1.second > stud2.second;
                    }

                    for (unsigned int i = 0; i <= min(stud1.first.size(), stud2.first.size()); i++) {
                        if (stud1.first[i] < stud2.first[i])
                            return true;
                    }

                    return stud1.first.size() < stud2.first.size();
                }
        );

        for (const auto& stud: copy_result_list) {
            cout << stud.first << " " << stud.second << endl;
        }
    }

    /**
     * Обработать запрос военкомата.
     *
     * Военкомат передаёт список имён и хочет призвать этих людей в армию.
     * Если у этих людей неуд-ы (оценка ниже 3), то:
     * - вернуть эти имена в ответе военкомату;
     * - удалить этих людей из общей таблицы (потому что теперь они не студенты).
     *
     * Входной параметр: сет строк с именами, кого хочет призвать военкомат.
     * Возвращаемое значение: сет строк с именами, кого действительно можно призвать
     * (или пустой сет, если призвать никого нельзя).
     * Гарантируется, что военкомат не будет пытаться призвать несуществующих студентов.
     */
    set<string> process_military_request(const set<string> &names) {
        set<string> potential_conscripts;
        auto copy_students = students;
        set_intersection(
                copy_students.begin(),
                copy_students.end(),
                names.begin(),
                names.end(),
                inserter(potential_conscripts, potential_conscripts.begin())
        );

        set<string> true_conscripts;
        auto copy_result_table = result_table;
        for (const auto& conscript : potential_conscripts) {
            if (result_table.find(conscript)->second < 3)
                true_conscripts.insert(conscript);
        }

        for (const auto& conscript : true_conscripts) {
            result_table.erase(conscript);
            students.erase(conscript);
        }
        result_list.clear();
        copy(
                result_table.begin(),
                result_table.end(),
                inserter(result_list, result_list.begin())
        );

        return true_conscripts;
    }
};

int main() {
    // Создали таблицу
    ResultsHolder rh;

    // Загрузили результаты
    rh.update("Alex", 6);
    rh.update("Anny", 5);
    rh.update("Ivan", 10);
    rh.update("Anastasia", 9);
    rh.update("Johnny", 1);
    rh.update("Alex", 7); // Апелляция у Alex, оценка обновляется
    rh.update("Nikita", 8);

    // Вывели в порядке убывания результата
    std::cout << "Exam results:" << std::endl;
    rh.print_standings();

    // Определили, кто идёт в армию
    auto to_military_service = rh.process_military_request({"Johnny", "Ivan"});

    // Вывели их на экран
    std::cout << "Are in army now:" << std::endl;
    for(const auto& s : to_military_service) {
        std::cout << s << std::endl;
    }

    // Вывели по алфавиту (но уже без Johnny, но Ivan остался с нами)
    std::cout << "Exam results:" << std::endl;
    rh.print_students();
}