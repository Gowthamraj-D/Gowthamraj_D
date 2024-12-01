int findPoisonedDuration(int* user, int len, int t) {
    int time = t;

    for (int i = len - 2; i >= 0; i--) {
        if (user[i + 1] - user[i] < t) time += user[i + 1] - user[i];
        else time += t;
    }

    return time;
}
