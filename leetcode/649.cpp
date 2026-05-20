class Solution {
public:
    string predictPartyVictory(string senate) {
        int r_vote = 0, d_vote = 0;

        int len = senate.size();
        int nr = 0, nd = 0;
        for (int i=0; i<len; ++i) {
            char c = senate[i];
            if (c == 'R') nr++;
            else if (c == 'D') nd++;
        }
        while(true) {
            for (int i=0; i<len; ++i) {
                char c = senate[i];

                if (c == 'x') continue;
                if (c == 'R') {
                    if (d_vote>0) {
                        senate[i] = 'x';
                        d_vote--;
                        nr--;
                        continue;
                    } else {
                        if (nd<=0) return "Radiant";
                        r_vote++;
                    }
                } else if (c == 'D') {
                    if (r_vote>0) {
                        senate[i] = 'x';
                        r_vote--;
                        nd--;
                        continue;
                    } else {
                        if (nr<=0) return "Dire";
                        d_vote++;
                    }
                } else {
                    return "Error";
                }
            }

            
        }
        
    }
};

