#include "change.h"

std::vector<long long> get_change(const std::vector<long long>& coins, long long amount) {
	long long c_amount = amount;
	std::vector<long long> denominations = coins;
	std::sort(denominations.begin(), denominations.end());
	std::vector<long long> ans;

	if (amount <= 0 || denominations[0] > amount)
		return ans;

	long long** dp = new long long* [amount + 1];
	for (int i = 0; i < amount + 1; i++) {
		dp[i] = new long long[2];
		dp[i][0] = 0;
		dp[i][1] = 0;
	}

	for (long long i = 0; i < denominations.size(); i++) {
		if (denominations[i] > amount) break;
		dp[denominations[i]][0] = 1;
		dp[denominations[i]][1] = 0;
		for (long long j = denominations[i] + 1; j <= amount; j++) {
			if (dp[j - denominations[i]][0] > 0 && (dp[j][0] == 0 || dp[j - denominations[i]][0] + 1 < dp[j][0])) {
				dp[j][0] = dp[j - denominations[i]][0] + 1;
				dp[j][1] = j - denominations[i];
			}
		}
	}

	if (dp[amount][0] > 0) {
		while (dp[amount][0] != 0) {
			ans.push_back(amount - dp[amount][1]);
			amount = dp[amount][1];
		}
	}

	for (int i = 0; i < c_amount + 1; i++)
		delete[] dp[i];
	delete[] dp;

	return ans;
}