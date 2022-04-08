#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#define ull unsigned long long
const int N=210;
using namespace std;

//去除字符前面的0
string remove_0(char x[])
{
    int len1 = strlen(x);
    char a[N]={""};
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    int a_len = strlen(a);
    //cout << "length remove a_len " << a_len<<endl;
    int num_0 = 0;
    for(int i = 0; i < a_len; i++)
    {
        if(a[i] == '0')
        {
            num_0++;
        }
        else
        {
            break;
        }
    }
    //cout << "num_0: " << num_0 << endl;
    if(num_0==0)
    {
        return a;
    }
    int re_len = a_len -num_0;
    char result[re_len+1] = {""};
    //char result[a_len -num_0];
    for(int i = 0; i < a_len-num_0; i++)
    {
        result[i] = a[i+num_0];
    }
    //cout << "length of result:" << strlen(result)<< endl;
    string re = result;
    //cout << "lenght of re:" << re.length() << endl;
    return re;
}
//比较两个数的大小,a大返回-1， b大返回1，相等返回0
int compare(char x[], char xx[])
{
    char a[N]={""},b[N]={""};
    int len1 = strlen(x);
    int len2 = strlen(xx);
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        b[i] = xx[i];
    }
    //cout << "a and b:" << a << " " << b << endl;
    int a_len = strlen(a);
    int b_len = strlen(b);
    if(a_len == b_len)
    {
        for(int i = 0; i < a_len; i++)
        {
            if(a[i] == b[i])
                continue;
            else if(a[i] > b[i])
                return -1;
            else
                return 1;
        }
        return 0;
    }
    else if(a_len > b_len)
        return -1;
    else
        return 1;
}
//函数介绍：输入为字符类型+长度，输出为字符串类型，长度根据.length得到，at(0)是个位数字
string bigMult2(char x[], char xx[])
{
    char s[N]={""}, ss[N]={""};
    int len1 = strlen(x);
    int len2  = strlen(xx);
    for(int i = 0; i< len1; i++)
    {
        s[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        ss[i] = xx[i];
    }
    string result;
    len1 = strlen(s);
    len2 = strlen(ss);
    int a[N]={0},b[N]={0};
    int c[N<<1]={0};
    for(int i=0;i<len1;i++)
    {
        a[len1-i]=s[i]-'0';
    }
    for(int i=0;i<len2;i++)
    {
        b[len2-i]=ss[i]-'0';
    }
    int p=0,tot;
    int t=0;
    for(int i=1;i<=len2;i++)
    {
        p=0;
        for(int j=1;j<=len1;j++)
        {
            t=j+i;
            tot=a[j]*b[i]+p+c[t-1];
            p=tot/10;
            c[t-1]=tot%10;
        }
        while(p)
        {
            c[t++]=p%10;
            p/=10;
        }
    }
    while(c[t]==0)
    {
        t--;
    }
    char zifu[t+1]={""};
    for(int i=t;i>=1;i--)
        zifu[i-1] = (char)(c[i]+48);
    for(int i = 0; i < t/2; i++)
    {
        char temp = zifu[t-1-i];
        zifu[t-1-i] = zifu[i];
        zifu[i] = temp;
    }
    result = zifu;
    //reverse(result.begin(),result.end());
    return result;
}
//计算a-b,输入的值就默认是a>b
string sub(char x[], char xx[])
{
    char a[N]={""},b[N]={""};
    int len1 = strlen(x);
    int len2 = strlen(xx);
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        b[i] = xx[i];
    }
    int a_len = strlen(a);
    int b_len = strlen(b);
    int sub_len = a_len - b_len;
    //cout << a_len<< " " << b_len << endl;
    int j;
    if(sub_len == 0)
        j = a_len - 1;
    else
        j = a_len- sub_len;
    for(int i = b_len-1; i >= 0; i--)
    {
        a[j] = (char)(a[j] - b[i] + 48);
        j--;
    }
    for(int i = a_len-1; i >=0; i--)
    {
        int temp = (int)a[i];
        if(temp < 48)
        {
            a[i] = (char)(a[i] + 10);
            a[i-1] = (char)(a[i-1] - 1);
        }
    }
    //if(a[0] == 9)
    // cout << "a:"<<a<<endl;
    string re = remove_0(a);
    return re;
}
//计算a%b
string get_mod(char x[], char xx[])
{
    char a[N]={""},b[N]={""};
    int len1 = strlen(x);
    int len2 = strlen(xx);
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        b[i] = xx[i];
    }
    //cout << "a and b " << a  << " " << b << endl;
    //string result;
    int a_len = strlen(a);
    int b_len = strlen(b);
    int c = compare(a, b);
    if(c == 0)
        return "0";
    if(c == 1)
    {
        string result = a;
        return a;
    }
    string d;
    //char d2[N] = {""};
    //strcpy(d2,d.c_str());
    int t = 50;
    while(c == -1)
    {
        d = "";
        d = sub(a,b);
        strcpy(a,d.c_str());
        c = compare(a, b);
        if(t>0)
        {
            //cout << a << " " << strlen(a) <<  " " << d.length()<< endl;
            t--;
        }
    }
    return d;
}

string mod(char x[], ull b, char xx[])//模幂运算: a^b mod m
{
    int len1 = strlen(x);
    int len2 = strlen(xx);
    char a[N]={""},m[N]={""};
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        m[i] = xx[i];
    }
    string result = "1";
    string base = a;
    string temp, temp2;
    char result2[N], base2[N], temp12[N],temp22[N];
    strcpy(result2,result.c_str());
    strcpy(base2,base.c_str());
    while(b>0)
	{
        if(b & 1==1)
		{
            temp = bigMult2(base2, result2);
            strcpy(temp12,temp.c_str());
            result = get_mod(temp12, m);
            strcpy(result2,result.c_str());
        }
        temp2 = bigMult2(base2,base2);
        strcpy(temp22,temp2.c_str());
        base = get_mod(temp22, m);
        strcpy(base2,base.c_str());
        b = b >> 1;
    }
    return result;
}

ull to_int(char a[])
{
    int a_len = strlen(a);
    char x[N] = {""};
    for(int i = 0; i < a_len; i++)
    {
        x[i] = a[i];
    }
    int x_len = strlen(x);
    unsigned long x_int = 0;
    for(int i = 0; i < x_len; i++)
    {
        x_int = (x_int * 10) + (int)(x[i]-48);
    }
    return x_int;
}

bool Primality_test(char xx[], int k)//素性测试
{
    //cout << xx << endl;
    unsigned long xx_int = 0;
    xx_int = to_int(xx);
    //cout << xx_int << endl;
	bool result = true;
    srand((unsigned long)time(NULL));
	for(int i = 0; i < k; i++)
	{
		unsigned long a = rand();
        a = a % (xx_int-3);
        a += 2;
        //cout << a<< endl;
        if(!(a >=2 && a <= xx_int -2))
            continue;
        char x[N] = {""};
        int j = 0;
        while(a > 0)
        {
            x[j]=(char)(a%10+48);
            a=a/10;
            j++;
        }
        //cout << "x:" << x << endl;
        char x_re[j+1]={""};
        for(int p = 0; p < j; p++)
        {
            x_re[p] = x[p];
        }
        for(int p = 0; p < j/2; p++)
        {
            char temp = x_re[j-1-p];
            x_re[j-1-j] = x_re[p];
            x_re[p] = temp;
        }
        unsigned long xx_int_1 = xx_int -1;
		string r = mod(x_re, xx_int_1, xx);
		if(r == "1")
		{
			result = true;
		}
		else
		{
			result = false;
			break;
		}
	}
	return result;
}

string add(char x[], char xx[])
{
    char a[N]={""},b[N]={""};
    int len1 = strlen(x);
    int len2 = strlen(xx);
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        b[i] = xx[i];
    }
    int a_len = strlen(a);
    int b_len = strlen(b);
    int sub_len;
    if(a_len < b_len)
        return add(xx, x);
    sub_len = a_len - b_len;
    //cout << a_len<< " " << b_len << endl;
    int j;
    j = a_len - 1;
    for(int i = b_len-1; i >= 0; i--)
    {
        a[j] = (char)(a[j] + b[i] - 48);
        j--;
    }
    char result[N]={""};
    for(int i = a_len-1; i >=0; i--)
    {
        int temp = (int)a[i];
        //cout << "temp:"<< temp << endl;
        if(temp > 57 && i!=0)
        {
            a[i] = (char)(a[i] - 10);
            a[i-1] = (char)(a[i-1] + 1);
        }
        if(temp > 57 && i==0)
        {
            a[0] = (char)(a[0]-10);
            result[0]= '1';
            for(int j = 1; j <= a_len; j++)
            {
                result[j] = a[j-1];
            }
            string re1 = remove_0(result);
            return re1;
        }
    }
    string re = remove_0(a);
    return re;
}

string three_mult(char x[], char xx[], char xxx[])
{
    char a[N]={""},b[N]={""},c[N]={""};
    int len1 = strlen(x);
    int len2 = strlen(xx);
    int len3 = strlen(xxx);
    for(int i = 0; i < len1; i++)
    {
        a[i] = x[i];
    }
    for(int i = 0; i < len2; i++)
    {
        b[i] = xx[i];
    }
    for(int i = 0; i < len1; i++)
    {
        c[i] = xxx[i];
    }
    int a_len = strlen(a);
    int b_len = strlen(b);
    int c_len = strlen(c);

    string temp, result;
    temp = bigMult2(a, b);
    char temp1[N];
    strcpy(temp1, temp.c_str());
    result = bigMult2(temp1, c);
    return result;
}
//求欧拉函数
ull euler(char x[])
{
    unsigned long n = to_int(x);
    unsigned long res=n,a=n;
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            res=res/i*(i-1);//先进行除法是为了防止中间数据的溢出
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
string CRT(char N1[], char N2[], char N3[], char C1[], char C2[], char C3[])
{
    int n1_len, n2_len, n3_len, c1_len, c2_len, c3_len;
    n1_len = strlen(N1);
    n2_len = strlen(N2);
    n3_len = strlen(N3);
    c1_len = strlen(C1);
    c2_len = strlen(C2);
    c3_len = strlen(C3);
    char n1[N]={""}, n2[N]={""}, n3[N]={""},c1[N]={""},c2[N]={""},c3[N]={""} ;
    for(int i = 0; i < n1_len; i++) n1[i] = N1[i];
    for(int i = 0; i < n2_len; i++) n2[i] = N2[i];
    for(int i = 0; i < n3_len; i++) n3[i] = N3[i];
    for(int i = 0; i < c1_len; i++) c1[i] = C1[i];
    for(int i = 0; i < c2_len; i++) c2[i] = C2[i];
    for(int i = 0; i < c3_len; i++) c3[i] = C3[i];
    n1_len = strlen(n1);
    n2_len = strlen(n2);
    n3_len = strlen(n3);
    c1_len = strlen(c1);
    c2_len = strlen(c2);
    c3_len = strlen(c3);
    //实现连乘
    char NN1[N]={""}, NN2[N]={""}, NN3[N]={""}, NN[N]={""};
    string N3_temp1 = bigMult2(n1, n2);
    strcpy(NN3, N3_temp1.c_str());
    string N2_temp1 = bigMult2(n1, n3);
    strcpy(NN2, N2_temp1.c_str());
    string N1_temp1 = bigMult2(n2, n3);
    strcpy(NN1, N1_temp1.c_str());
    //这里是总的乘积
    string N_temp1 = bigMult2(NN3, n3);
    strcpy(NN, N_temp1.c_str());

    ull euler1 = euler(n1);
    ull euler2 = euler(n2);
    ull euler3 = euler(n3);

    string t1_temp, t2_temp, t3_temp;
    char t1[N]={""}, t2[N]={""}, t3[N]={""};
    //unsigned long n1_int = to_int(n1);
    t1_temp = mod(NN1, (euler1-1), n1);//NN1^(n1_int-2) mod n1
    strcpy(t1, t1_temp.c_str());
    //unsigned long n2_int = to_int(n2);
    t2_temp = mod(NN2, (euler2-1), n2);
    strcpy(t2, t2_temp.c_str());
    //unsigned long n3_int = to_int(n3);
    t3_temp = mod(NN3, (euler3-1), n3);
    strcpy(t3, t3_temp.c_str());//
    //之后就事实现加法，得出x，最后开三次方根

    //10月31日实现了加法和三连乘，但是对于开三次方根还是毫无头绪
    string one = three_mult(t1, NN1, c1);
    string two = three_mult(t2, NN2, c2);
    string three = three_mult(t3, NN3, c3);
    char one_c[N]={""};
    char two_c[N]={""};
    char three_c[N]={""};
    strcpy(one_c, one.c_str());
    strcpy(two_c, two.c_str());
    strcpy(three_c, three.c_str());
    string add_temp = add(one_c, two_c);
    char add_c[N]={""};
    strcpy(add_c, add_temp.c_str());
    string re_fine = add(add_c, three_c);
    char re_fine_c[N]={""};
    strcpy(re_fine_c, re_fine.c_str());
    string result = get_mod(re_fine_c, NN);//cout << "result" << result << endl;
    return result;
}

string sancifang(char x[])
{
    string re = three_mult(x, x, x);
    return re;
}

string to_char(ull x)
{
    char a[N]={""};
    int i = 0;
    while(x>0)
    {
        a[i] = (char)((x%10)+48);
        //cout << "i:" << i << a[i] << endl;
        i++;
        x=x/10;
    }
    string re = a;
    reverse(re.begin(), re.end());
    return re;
}

string sancigen(char x[])
{
    ull x_int = to_int(x);
    char a[N]={""};
    int x_len = strlen(x);
    for(int i = 0; i < x_len; i++)
    {
        a[i] = x[i];
    }
    //利用二分法进行开三次方
    ull big = x_int, small = 0;
    ull temp = (big+small)/2;
    char temp1[N]={""};
    string temp_string = to_char(temp);
    strcpy(temp1, temp_string.c_str());
    string x_string = a;//待开方的数字
    //cout << "x_string:"<<x_string << endl;
    string temp3 = sancifang(temp1);
    int k = 1000;
    while(temp3 != x_string)
    {
        k--;
        if(k < 0) return "";//确保不死机

        char m[N] = {""}, n[N]={""};
        strcpy(m, temp3.c_str());
        strcpy(n, x_string.c_str());
        int com = compare(m, n);
        if(com == -1)
        {
            big = temp;
            temp = (big+small)/2;
            temp_string = to_char(temp);
            strcpy(temp1, temp_string.c_str());
            temp3 = sancifang(temp1);
        }
        else
        {
            small = temp;
            temp = (big+small)/2;
            temp_string = to_char(temp);
            strcpy(temp1, temp_string.c_str());
            temp3 = sancifang(temp1);
        }

    }
    return temp1;
}

string RSA_encry(char p[], char q[], ull e, char m[])
{
	//进行素性测试
	if(!(Primality_test(p, 50) && Primality_test(q, 50)))
	{
		cout << "错误：你的输入不满足素性检验" << endl;
		return "0";
	}
	string mult = bigMult2(p, q);
    char mult2[N];
    strcpy(mult2, mult.c_str());
    string result = mod(m, e, mult2);
    return result;
}

string RSA_decry(char p[], char q[], ull d, char c[])
{
	if(!(Primality_test(p, 50) && Primality_test(q, 50)))
	{
		cout << "错误：你的输入不满足素性检验" << endl;
		return "0";
	}
	//cout << sizeof(unsigned long long) << endl;
    string mult = bigMult2(p, q);
    //cout << mult << endl;
	char mult2[N];
    strcpy(mult2, mult.c_str());
    string result = mod(c, d, mult2);
   // cout << result << endl;
    return result;
}

string min_e_attack(int e, char n1[], char n2[], char n3[], char c1[], char c2[], char c3[])
{
	string temp = CRT(n1, n2, n3, c1, c2, c3);
    char temp_char[N]={""};
    strcpy(temp_char, temp.c_str());
    string result = sancigen(temp_char);
    return result;
}

int main()
{
	int x = 1;
	while(x==1)
	{
		cout << "执行加密或者解密(加密：1 解密；2 小e攻击：3):" ;
		int a;
		cin >> a;
		if(a == 1)
		{
			cout << "请输入p,q,e,m:" ;
            string p, q, m;
            ull e;
			cin >> p >> q >> e >> m;
            char p1[N] = {""}, q1[N]={""}, m1[N]={""};
            strcpy(p1, p.c_str());
            strcpy(q1, q.c_str());
            strcpy(m1, m.c_str());
			string c = RSA_encry(p1, q1, e, m1);
			if(c != "0")
                cout << "加密后的密文c为：" << c << endl;
		}
		else if(a == 2)
		{
			cout << "请输入p,q,d,c:" ;
            string p, q, c;
            ull d;
			cin >> p >> q >> d >> c;
            char p1[N] = {""}, q1[N]={""}, c1[N]={""};
            strcpy(p1, p.c_str());
            strcpy(q1, q.c_str());
            strcpy(c1, c.c_str());
			string m = RSA_decry(p1, q1, d, c1);
			if(m != "0")
                cout << "解密后的明文m为：" << m << endl;
		}
		else
		{
			//int c_e[3];
            string c1,c2,c3,n1,n2,n3;
			int e = 3;//e默认为3
			cout << "请输入e,n1,n2,n3,c1,c2,c3:";
			cin >> e >> n1 >> n2 >> n3 >> c1 >> c2 >> c3;
            char n1_char[N]={""}, n2_char[N]={""}, n3_char[N]={""}, c1_char[N]={""}, c2_char[N]={""}, c3_char[N]={""};
            strcpy(n1_char, n1.c_str());
            strcpy(n2_char, n2.c_str());
            strcpy(n3_char, n3.c_str());
            strcpy(c1_char, c1.c_str());
            strcpy(c2_char, c2.c_str());
            strcpy(c3_char, c3.c_str());
            string m = min_e_attack(3, n1_char, n2_char, n3_char, c1_char, c2_char, c3_char);
            cout << "破解后的明文m为：" << m << endl;
		}
		cout << "是否继续(继续：1 结束：2)：";
		cin >> a;
		if(a == 2)
			return 0;
	}
}
