#include "filter/SkippingAverage.h"
#include <stdio.h>

int main() {
    SkippingAverage_init();

    uint16_t data[] = {
            0, 0, 0, 0, 1, 2, 3, 4, 5, 6,
            13, 29, 0, 34, 2, 0, 30, 4, 4,
            4, 4, 4, 0, 0, 0, 2, 3, 0, 2, 3, 4,
            };

    for(int i = 0; i < 31; i++) {
        uint16_t result = SkippingAverage_filter_output(data[i]);
        printf("%d\n", result);
    }

    return 0;
}
