import java.io.*;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		// INPUT
		var br = new BufferedReader(new InputStreamReader(System.in));

		int n = Integer.parseInt(br.readLine());

		int[] top = new int[n];
		int[] bottom = new int[n];

		var topSt = new StringTokenizer(br.readLine());
		var bottomSt = new StringTokenizer(br.readLine());
		br.close();

		for (int i=0;i<n;i++) {
			top[i] = Integer.parseInt(topSt.nextToken());
			bottom[i] = Integer.parseInt(bottomSt.nextToken());
		}

		// SOLUTION
		int[] answer = new int[n];
		answer[0] = 0;

		for(int i=1;i<n;i++) {
			assert top[i] > bottom[i]; // throw Exception
			int previous = answer[i-1];
			answer[i] = previous;

			if (previous >= top[i]) /* 다음 천장보다 큰 경우 */ {
				answer[i] = top[i] - 1;
			} else if(previous <= bottom[i])/* 다음 바닥보다 작은 경우*/ {
				answer[i] = bottom[i] + 1;
			}
		}

		var sb = new StringBuilder();
		sb.append(answer[0]);
		for (int i=1; i<n; i++) {
			sb.append(' ');
			sb.append(answer[i]);
		}

		System.out.println(sb.toString());
	}
}
