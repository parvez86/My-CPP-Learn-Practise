vector<int> parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    vector<int> res;
    int i=0;
    string a;
    while(getline(ss, a, ',')){
        res.push_back(stoi(a));
    }
    return res;
}
