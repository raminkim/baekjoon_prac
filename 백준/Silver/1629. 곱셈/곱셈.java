import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static long c;

	public static void main(String[] args) throws IOException {
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		String ip[] = buf.readLine().split(" ");
		long a = Long.parseLong(ip[0]);
		long b = Long.parseLong(ip[1]);
		c = Long.parseLong(ip[2]);
		
		System.out.println(pow(a, b));
	}
	
	public static long pow(long num, long exp) {
		
		//지수가 1일 경우에는 그냥 c의 나머지 연산을 하면 됨.
		if (exp == 1) { return num % c; }
		
		// 지수의 절반에 해당되는 값을 이용해 num^(exp/2)를 구한다.
		long temp = pow(num, exp/2);
		
		// 홀수인 경우에는 추가로 tmp 값을 한번 더 곱해줘야 한다.
		// num^7 = num^3 * num^3 * num이기 때문이다.
		
		/**
		 * 모듈러 산술 연산의 특징
		(a * b) % c = (a % c * b % c) % c 이므로,
		(temp*temp*num)%c = ((temp * (temp*1) % c) * (num % c)) % c
	     = (((temp * temp % c) % c) * (num % c)) % c
	     = ((temp * temp % c) * num) % c
		**/
		
		if (exp % 2 == 1) {
			return (temp*temp % c) * num % c;
		}
		
		return temp * temp % c;
	}
}