#include <iostream>
#include <stack>

using namespace::std;

int moves = 0;

void dput(stack<int> *source, stack<int> *dest) {
stack<int> &ts = *source, &td = *dest;
if (td.empty() || td.top() > ts.top()) {
cout << "\tMoving Disk #\t" << ts.top() << "\t(" << &ts << " -> " << &td << ")" << endl;
td.push(ts.top());
ts.pop();
}
}

void hanoi(int disks, stack<int> *source, stack<int> *dest, stack<int> *spare) {
stack<int> &ts = *source, &td = *dest, &tp = *spare;
if (disks == 1) {
dput(&ts, &td); moves++;
} else {
hanoi(disks - 1, &ts, &tp, &td);
dput(&ts, &td); moves++;
hanoi(disks - 1, &tp, &td, &ts);
}
}

int main() {
stack<int> t1, t2, t3;
int dnum, i;
cout << "\n\tEnter the number of disks: ";
cin >> dnum; cin.ignore();
for (i = dnum; i >= 1; i--) {
t1.push(i);
}
cout << endl
<< "\tTowers:" << endl
<< "\t\tTower 1:\t" << &t1 << endl
<< "\t\tTower 2:\t" << &t2 << endl
<< "\t\tTower 3:\t" << &t3 << endl
<< endl;
hanoi(dnum, &t1, &t2, &t3);
cout << endl
<< "\tNumber of moves:\t" << moves;
cin.get();
return 0;
}