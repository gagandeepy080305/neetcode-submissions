class Solution {
public://optimal
//T.C. - O(n log n)
//S.C. - O(1)
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0)
            return false;

        sort(hand.begin(), hand.end());

        unordered_map<int,int> freq;

        for(int x : hand)
            freq[x]++;

        for(int x : hand) {

            if(freq[x] == 0)
                continue;

            int count = freq[x];

            for(int j = 0; j < groupSize; j++) {

                int curr = x + j;

                if(freq[curr] < count)
                    return false;

                freq[curr] -= count;
            }
        }

        return true;
    }
};