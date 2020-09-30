int Solution::solve(int A, int B, int C) {
    int pos = (C + A - 1) % B;
    // Return B if pos is 0
    // For example: A = 7, B = 7, C = 1
    return (pos == 0) ? B : pos;
}
