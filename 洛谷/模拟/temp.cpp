#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x7ffffffffffff;
//�����
const string work_name[] = {"BangZhu", "FuBangZhu", 
							"HuFa", "ZhangLao", 
                            "TangZhu", "JingYing", "BangZhong"};
//����ְλ�����֣����մӴ�С��˳������
const long long work_num[] = {1, 3, 5, 9, 16, 41, inf};
//���մӴ�С��˳��ÿ��ְλ���ŵ�������������ְλ��ģ�
map<string, int> w_n_level;
//һ��map����stringΪ��������int
//���Կ���һ�������±�Ϊstring���͵�int����
//���map�����ְλ�Ĵ�С��ϵ��ְλС��ֵС��ְλ���ֵ��
//map��main������ͷ��ʼ��
struct player {
    string name, work;
    //���ƺ�ְλ
    long long help, level;
    //�ﹱ�͵ȼ�
    int inn;
    //���������ŵ�λ��
} arr[150];
//һ���ṹ�壬��ÿ���˵���Ϣ
int n;
//������
bool com(player a, player b) {
    if (a.help == b.help) {
    	//�ﹱ��ͬ�����ڶ��ؼ�������˳����
        return a.inn < b.inn;
    } else {
    	//���ﹱ��
        return a.help > b.help;
    }
}
//��һ������Ҫ�õĺ���
bool com2(player a, player b) {
    if (a.work == b.work) {//��һ�ؼ������
        if (a.level == b.level) {
        	//�ڶ��ؼ���Ҳ��ȣ�������˳��
            return a.inn < b.inn;
        } else {//���ڶ��ؼ��ֵȼ���
            return a.level > b.level;
        }
    } else {//����һ�ؼ���ְλ��
        return w_n_level[a.work] < w_n_level[b.work];
    }
}
//�ڶ�������
int main() {
    for (int i = 0; i < 7; ++i) {
        w_n_level[work_name[i]] = i;
    }
    //��ʼ��map
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].name >> arr[i].work >> arr[i].help >> arr[i].level;
        //����ÿ���˵���Ϣ
        if (arr[i].work == work_name[0]) {
            arr[i].help = inf;
            //�ǰ������ﹱ��Ϊ����󣬱�֤����ǰ
        } else if (arr[i].work == work_name[1]) {
            arr[i].help = inf - 5;
            //�Ǹ��������ﹱ�������Сһ�㣬��֤�ڰ�����������ǰ
        }
        arr[i].inn = i;
        //��i�������
    }
    sort(arr + 1, arr + n + 1, com);
    //��һ������
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 7; ++j) {//�����ĸ�����
            if (i <= work_num[j]) {//�������ϱ�׼
                arr[i].work = work_name[j];//����ְ��
                break;//�����η���
            }
        }
    }//��ÿ���˵�ְλ�����
    sort(arr + 1, arr + n + 1, com2);
    //�ڶ�������
    for (int i = 1; i <= n; ++i) {
        cout << arr[i].name << " " << arr[i].work << " " << arr[i].level << endl;
    }//������
    getchar();	getchar();//���Լ�����������ͣ�õģ�����ȥ��
    return 0;
}
