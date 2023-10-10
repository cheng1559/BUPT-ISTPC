import java.util.Scanner;

public class jury {
	public static void main(String[] args) {
		var in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(n + 1);
		while (--n > 0) {
			System.out.print(in.nextInt() + " ");
		}
		int x = in.nextInt();
		System.out.println((x + 1) + " " + x * (x + 1));
	}
}