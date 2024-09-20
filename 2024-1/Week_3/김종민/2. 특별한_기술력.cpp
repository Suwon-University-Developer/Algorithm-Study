// 1. �Ź� ���� Ű�� ū �л��� Ű�� ���� Ű�� ū �л��� �����ϰ� �� ���ϸ� ���� ������? 
// > �ð� �ʰ�

// 2. �������� ������ �ϰ� ����, �Ź� ���� Ű�� ū �л��� ã�� �ʿ䰡 ���� (N-1-i)�� ���� ū �л��̴� �ð� �ʰ��� �������� ������? 
// > �ð� �ʰ�

// 3. ���� for���� �������� �ν���. dp�� �̿��ϴ� ���� �ƴұ�? dp�� ����ϱ� ���� �ݺ��Ǵ� ������ ã�� ���� �õ�
// 4. dp�� ����� �ʿ� ���� (N - 1 - i) * 2^(N - i - 1)�� �� ���� ���� �������� �ν��ߴ�. �ٵ� Ʋ�ȴ�.
// > �����÷ο� �� ���� ó�� X

// 5. ��¥ ��¥ ��¥ ��¥ ����� ������ �����ڸ� ���������� ���� �Լ��� ����ϴٺ��� �� ���� for���� ���������.

// 6. ��� �ϸ� ���� �Լ��� for���� ���� �� ������?
// > dp�� �̿��Ͽ� ������ ����� 2^(N - 1)��°���� �̸� ���صдٸ�?
// > ����

// �̰� ��� �ǹ�2 ������

#include <iostream>
#include <vector>
#include <algorithm>

using LL = long long;

int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	const auto CONSTRAINT = 1000000007;

	auto N = 0;
	std::cin >> N;

	auto Ns = std::vector<int>(N);
	for (auto i = 0; i < N; i++)
		std::cin >> Ns[i];

	std::sort(Ns.begin(), Ns.end());

	auto mul = std::vector<LL>(N);
	mul[0] = 1;
	for (auto i = 1; i < N; i++)
		mul[i] = (2 * mul[i - 1]) % CONSTRAINT;

	auto answer = LL(0);
	for (int i = N - 1; i >= 0; i--)
		answer = (answer + (Ns[i] * (mul[i] % CONSTRAINT)) % CONSTRAINT) % CONSTRAINT;

	std::cout << answer;

	return 0;
}