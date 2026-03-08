import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		// INPUT
		var br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		int[] w = new int[n+1];
		var st = new StringTokenizer(br.readLine());
		for(int i=1;i<=n;i++){
			w[i] = Integer.parseInt(st.nextToken());
		}



		// SOLUTION
		boolean[][] dp = new boolean[n+1][40001];

		for (int i=1;i<=n;i++){
			int cur = w[i];
			dp[i][cur] = true; // 현재 값
			for(int j=1;j<40001;j++) {
				dp[i][j] |= dp[i-1][j]; // 이전 값

				if (dp[i-1][j]) {
					if (j+cur <= 40000) dp[i][j + cur] = true;
					if (Math.abs(j-cur) <= 40000) dp[i][Math.abs(j-cur)] = true;
				}
			}

		}

		// THEN RETURN
		int m = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		for(int i=0;i<m;i++){
			int req = Integer.parseInt(st.nextToken());
			if(dp[n][req]) {
				sb.append('Y');
			} else {
				sb.append('N');
			}
			if (i < m-1) sb.append(' ');
		}

		System.out.println(sb);
	}
}
