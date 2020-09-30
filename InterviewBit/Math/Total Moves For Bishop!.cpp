// https://stackoverflow.com/questions/58498929/what-is-the-logic-behind-calculating-diagonals-on-a-chessboard
/* Explanation:
The top-left distance to the edge of the board is indeed min(r, c) - 1. Given that the bishop starts on rank r, it can move up no more than r - 1 ranks before landing on the first rank. It may hit the first file before that if c < r, in which case it will only be able to move c - 1 squares. For example if the bishop starts at r = 5 and c = 4, it will be able to move three squares, not four. Thus the top-left formula is min(r - 1, c - 1), which can be refactored to min(r, c) - 1. Similarly, when heading towards the bottom-left corner, the rank increases while the file decreases. The bishop can move at most 8 - r ranks and at most c - 1 files, so the bottom-left formula is min(8 - r, c - 1). That can be refactored to 8 – max(r, 9 – c), although this expression seems more convoluted. */

int Solution::solve(int A, int B) {
    int topLeft = min(A - 1, B - 1);
    int topRight = min(A - 1, 8 - B);
    int bottomLeft = min(8 - A, B - 1);
    int bottomRight = min(8 - A, 8 - B);
    
    return (topLeft + topRight + bottomLeft + bottomRight);
}
