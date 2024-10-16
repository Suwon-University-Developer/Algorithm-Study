#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void) {
    int rows, cols, wait;
    scanf("%d %d", &cols, &rows);
    scanf("%d", &wait);

    if ((rows * cols) < wait)
    {
        printf("0");
        exit(0);
    }



    int arr[rows][cols]; // 2���� �迭 ����
    int num = 1; // �迭�� ä�� ���� �ʱ�ȭ
    int x = rows - 1, y = 0; // ���� �Ʒ����� ���� (��: rows-1, ��: 0)

    // �̵� ���� ���� (�ð� ����: �� -> ������ -> �Ʒ� -> ����)
    int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
    int d = 0; // ���� �ε��� (0: ��, 1: ������, 2: �Ʒ�, 3: ����)

    // �迭�� 0���� �ʱ�ȭ
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = 0;

    for (int i = 0; i < rows * cols; i++) {
        arr[x][y] = num++; // ���� ��ġ�� ���� ä���

        // ���� ��ġ ���
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        // ������ ����ų� �̹� ���� ä���� ��� ���� ��ȯ
        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || arr[nx][ny] != 0) {
            d = (d + 1) % 4; // ���� ��ȯ
            nx = x + dir[d][0];
            ny = y + dir[d][1];
        }

        // ���� ��ġ�� �̵�
        x = nx;
        y = ny;
    }
    int ax, ay;
    // �迭 ���
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == wait)
            {
                ax = i;
                ay = j;
                break;
            }
        }
    }



    int ansx = ay + 1;
    int ansy = rows - ax;

    printf("%d %d", ansx, ansy);
    return 0;
}
