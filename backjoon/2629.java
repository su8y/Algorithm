import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int weightCount = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] weights = new int[weightCount];

        for (int i = 0; i < weightCount; i++) {
            weights[i] = Integer.parseInt(st.nextToken());
        }

        boolean[] dp = new boolean[40_001];

        dp[0] = true;

        for (int weight : weights) {
            for (int i = dp.length - 1; i >= weight; i--) {
                dp[i] |= dp[i - weight];
            }
        }

        for (int weight : weights) {
            for (int i = 0; i < dp.length - weight; i++) {
                dp[i] |= dp[i + weight];
            }
        }

        int count = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < count; i++) {
            int bead = Integer.parseInt(st.nextToken());

            sb.append(dp[bead] ? 'Y' : 'N').append(" ");
        }

        System.out.print(sb);
    }
}
