int isWinner(int* player1, int player1Size, int* player2, int player2Size) {
    int p1 = 0;
    for (int i = 0; i < player1Size; i++) {
        int score = player1[i];
        int mult = 1;
        if (i - 1 >= 0 && player1[i-1] == 10) mult = 2;
        if (i - 2 >= 0 && player1[i-2] == 10) mult = 2;
        p1 += score * mult;
    }
    int p2 = 0;
    for (int i = 0; i < player2Size; i++) {
        int score = player2[i];
        int mult = 1;
        if (i - 1 >= 0 && player2[i-1] == 10) mult = 2;
        if (i - 2 >= 0 && player2[i-2] == 10) mult = 2;
        p2 += score * mult;
    }
    if (p1 == p2) return 0;
    return (p1 > p2 ? 1 : 2);
}