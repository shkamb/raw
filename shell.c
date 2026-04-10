long sc(long n, long a1, long a2, long a3) {
    long r;
    __asm__ volatile (
        "mov x0, %1\nmov x1, %2\nmov x2, %3\nmov x16, %4\nsvc #0x80\nmov %0, x0"
        : "=r"(r) : "r"(a1), "r"(a2), "r"(a3), "r"(n) : "x0","x1","x2","x16"
    );
    return r;
}

int main() {
    char b[128];
    char *v[2] = {b, 0};
    while (1) {
        sc(0x2000004, 1, (long)"> ", 2);
        int n = sc(0x2000003, 0, (long)b, 128);
        if (n <= 1) continue;
        b[n-1] = 0;
        if (sc(0x2000002, 0, 0, 0) == 0) {
            sc(0x200003b, (long)b, (long)v, 0);
            sc(0x2000001, 1, 0, 0);
        }
        for(volatile int i=0; i<5000000; i++);
    }
return 0;
}
