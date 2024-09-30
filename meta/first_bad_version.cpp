//
// Created by 62339 on 2023/11/1.
//
class first_bad_version {
public:
    virtual bool isBadVersion(int version);

    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (!isBadVersion(mid)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};