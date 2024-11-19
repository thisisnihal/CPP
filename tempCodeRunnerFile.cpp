    int curr, prev;
    cin >> n >> prev;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        cin >> curr;
        // cout << prev << " "  << curr << ed;
        if (prev - curr > 1) flag = true;
        prev = curr;
    }
    if (flag) cout << "NO" << ed;
    else cout << "YES" << ed;
}