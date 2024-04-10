#include <stdio.h>

int main() {
    int 
		ad, 
		op, 
		h;

    printf("Ternas Pitagoricas:\n");

    for (ad = 1; ad <= 500; ++ad) {
        for (op = ad; op <= 500; ++op) {
            for (h = op; h <= 500; ++h) {
                if (ad * ad + op * op == h * h) {
                    printf("%d (%d, %d, %d)\n", ad+op+h, ad, op, h);
                }
            }
        }
    }

    return 0;
}

