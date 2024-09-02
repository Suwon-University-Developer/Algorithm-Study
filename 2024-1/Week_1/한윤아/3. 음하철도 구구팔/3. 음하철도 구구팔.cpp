#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define min(a,b)(a<b?a:b)
int Xs, Ys;
int Xe, Ye, dx, dy;
double get_distance(int x1, int y1) {
                double tmp = pow((x1 - Xs), 2) + pow((y1 - Ys), 2);
                return sqrt(tmp);
}
void fix_dxdy() {//dx,dy�� ���� �۰� ����� �ż���(1�ʸ��� X) �̵��ϴ� ��ġ ���ϱ�
                int small = min(dx, dy);
                if (small == 0) {//�� �� �ϳ��� 0�̸� �ٸ� �ϳ��� 1�� ����
                                if (dx == 0) dy = 1;
                                else dx = 1;
                                return;
                }
                //�ִ������� ���ؼ� ������
                while (small) {
                                if (dx % small == 0 && dy % small == 0) break;
                                else small--;
                }
                if (small > 1) { dx /= small; dy /= small; }
}
int main()
{
                scanf("%d%d", &Xs, &Ys);
                scanf("%d%d%d%d", &Xe, &Ye, &dx, &dy);
                //������ ��� �����忡 ��������ٰ� ��� ���� �־���
                //���� ����������� �Ÿ�<=���� ����������� �Ÿ��� ���� ���� ������ ���
                fix_dxdy();
                while (1) {
                                if (get_distance(Xe, Ye) < get_distance(Xe + dx, Ye + dy)) break;
                                else {
                                                Xe += dx;
                                                Ye += dy;
                                }
                }
                printf("%d %d", Xe, Ye);
}