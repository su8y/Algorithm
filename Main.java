import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		// GIVEN
		var br = new BufferedReader(new InputStreamReader(System.in));

		var st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());

		int[][] graph = new int[n+1][m+1];

		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= m; j++) {
				graph[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		// WHEN
		int[][] cache = new int[n+1][m+1];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cache[i][j] = Math.max(cache[i][j], cache[i-1][j-1] + graph[i][j]);
				cache[i][j] = Math.max(cache[i][j], cache[i][j-1] + graph[i][j]);
				cache[i][j] = Math.max(cache[i][j], cache[i-1][j] + graph[i][j]);
			}
		}

		// THEN
		System.out.println(cache[n][m]);
	}
}
