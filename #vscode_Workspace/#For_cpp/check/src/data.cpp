#include <bits/stdc++.h>
using namespace std;

static const int MAX_A = 26;

// 生成 [L, R] 范围内的随机整数
int rnd(int L, int R)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(L, R);          // 闭区间
    return dis(gen);
}

int main() {

    int N0 = 10;     // 初始序列长度，可调整
    int M = 10;      // 操作次数，可调整
    int MAXLEN = 33 * N0;

    vector<int> A(N0);
    for (int &x : A) x = rnd(1, MAX_A);

    // 保存生成的输入内容（因为后面需要输出）
    vector<string> input_lines;

    // 第一行
    {
        ostringstream out;
        out << N0 << " " << M;
        input_lines.push_back(out.str());
    }

    // 初始序列
    {
        ostringstream out;
        for (int i = 0; i < N0; i++) {
            if (i) out << " ";
            out << A[i];
        }
        input_lines.push_back(out.str());
    }

    // 开始生成操作并执行真实模拟
    for (int op_id = 1; op_id <= M; op_id++) {
        int op = rnd(1, 3);

        // 为了尽量不爆长度，我们限制某些操作概率
        if (A.size() > MAXLEN * 0.8) {
            // 序列太长时尽量产生 "缩短" 的操作
            while (op == 2) op = rnd(1, 3); 
        }

        {
            ostringstream out;
            out << op;
            input_lines.push_back(out.str());
        }

        int L = A.size();

        if (op == 1) {
            // 查找替换
            int L1 = rnd(1, min(5, max(1, L)));  // 限制 L1 保证能匹配
            vector<int> seq1(L1);
            for (int &x : seq1) x = rnd(1, MAX_A);

            // 替换序列可能增加长度，但受 MAXLEN 限制
            int L2 = rnd(1, 8);
            if (L + (L2 - L1) > MAXLEN) {
                L2 = L1; // 避免爆长度
            }
            vector<int> seq2(L2);
            for (int &x : seq2) x = rnd(1, MAX_A);

            {
                ostringstream out;
                out << L1;
                for (int x : seq1) out << " " << x;
                input_lines.push_back(out.str());
            }
            {
                ostringstream out;
                out << L2;
                for (int x : seq2) out << " " << x;
                input_lines.push_back(out.str());
            }

            // --- 执行模拟 ---
            bool found = false;
            for (int i = 0; i + L1 <= L && !found; i++) {
                bool ok = true;
                for (int k = 0; k < L1; k++) {
                    if (A[i + k] != seq1[k]) { ok = false; break; }
                }
                if (ok) {
                    // 替换第一个
                    vector<int> B;
                    B.insert(B.end(), A.begin(), A.begin() + i);
                    B.insert(B.end(), seq2.begin(), seq2.end());
                    B.insert(B.end(), A.begin() + i + L1, A.end());
                    A.swap(B);
                    found = true;
                }
            }
        }

        else if (op == 2) {
            // 插入平均数
            vector<int> B;
            for (int i = 0; i < L; i++) {
                B.push_back(A[i]);
                if (i + 1 < L && ((A[i] + A[i+1]) % 2 == 0)) {
                    int mid = (A[i] + A[i+1]) / 2;
                    if ((int)B.size() < MAXLEN) {
                        B.push_back(mid);
                    }
                }
            }
            A.swap(B);
        }

        else if (op == 3) {
            // 翻转
            int l = rnd(1, max(1, L));
            int r = rnd(l, max(1, L));
            {
                ostringstream out;
                out << l << " " << r;
                input_lines.push_back(out.str());
            }

            // 执行翻转
            if (L > 0) reverse(A.begin() + (l-1), A.begin() + r);
        }
    }

    // 输出最终结果（用于比对正确答案）
    vector<int> final_ans = A;

    // ---------- 输出整个测试用例 ----------
    // 输入
    for (auto &s : input_lines) cout << s << "\n";
    // 输出
    // cout << (int)final_ans.size();
    // for (int i = 0; i < (int)final_ans.size(); i++) {
    //     if (i) cout << " ";
    //     cout << final_ans[i];
    // }
    // cout << "\n";

    return 0;
}
