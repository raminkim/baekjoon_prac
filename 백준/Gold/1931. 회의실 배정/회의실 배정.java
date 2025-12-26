import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[]args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		int[][] lst = new int[n][2];

		for (int i=0; i<n; i++) {
			String s = reader.readLine();
			StringTokenizer st = new StringTokenizer(s);
			lst[i][0] = Integer.parseInt(st.nextToken());
			lst[i][1] = Integer.parseInt(st.nextToken());	
		}
		Arrays.sort(lst, new Comparator<int[]>() {
		
			public int compare(int[] a1, int[] a2) {
				if (a1[1] == a2[1]) {
					return a1[0] - a2[0];
				}
				return a1[1] - a2[1];
			}
		});
		
		int count = 0;
		int pre_end_time = 0;
		
		for (int j=0; j<n; j++) {
			if (pre_end_time <= lst[j][0]) {
				pre_end_time = lst[j][1];
				count++;
			}
		}
		System.out.println(count);
		
	}
}