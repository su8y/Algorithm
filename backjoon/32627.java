import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static int stoi(String s) {
		return Integer.parseInt(s);
	}

	public static void main(String[] args) throws IOException {
		var br = new BufferedReader(new InputStreamReader(System.in));
		var st = new StringTokenizer(br.readLine());

		int N = stoi(st.nextToken());
		int M = stoi(st.nextToken());
		String S = br.readLine();

		// SOLUTION
		int[] count = new int[26];
		char[] sorted = S.toCharArray();

		Arrays.sort(sorted);

		for (int i = 0; i < M; i++) {/* M개 만큼 count 증가 */
			count[sorted[i] - 'a']++;

		}

		var sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			int cur = S.charAt(i) - 'a';
			if (count[cur] > 0) { /* 지우기 */
				count[cur]--;
				continue;
			}

			sb.append(S.charAt(i)); /* 적재 */
		}
		System.out.println(sb);

	}
}
