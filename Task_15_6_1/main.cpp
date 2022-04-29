#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int>vec = {-1, -2, 20, -21, 19, 0, 2, -4, 5, 7, -4, 2, -4, 5};

    int ind_s = 0, ind_f = 0, cur_sum = 0, max = 0, start_sum = 0;

    for(int i = 0; i < vec.size() - 1; i++) {
        // определяем начало отсчета суммы
        if (vec[i]  + start_sum >= start_sum) {
            start_sum = vec[i];
            ind_s = i;
        }else if (vec[i]  + start_sum < start_sum) {
            start_sum = 0;
        }
        // обнуляем сумму, если текущий индекс больше чем предыдущий максимальный
        if (ind_s == i) {
            max = 0;
            cur_sum = 0;
        }
        // увеличиваем текущую сумму
        if (ind_s > 0) {
            cur_sum += vec[i];
        }
        // увеличиваем максимальную сумму, если видно что текущая растет
        if (cur_sum + vec[i] > max ) {
            max = cur_sum;
        }
        // определяем конечный индекс для максималной суммы
        if (max + vec[i] > max) {
            ind_f = i;
        }
    }

    cout << "Current sum = " << cur_sum << "\n";
    cout << "Max sum = " << max << "\n";
    cout << "Index start = " << ind_s << "\n";
    cout << "Index finish = " << ind_f << "\n";
}