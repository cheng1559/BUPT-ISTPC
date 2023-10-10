import java.util.Scanner;

public class jury {
	static class Point {
		int x, y;

		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	static double interpolate(int x, Point[] f) {
		for (int i = 0; i < f.length; i++) {
			if (f[i].x == x) {
				return f[i].y;
			}
		}
		double res = 0;
		for (int i = 0; i < f.length; i++) {
			double num = 1, den = 1;
			for (int j = 0; j < f.length; j++) {
				if (i != j) {
					num *= x - f[j].x;
					den *= f[i].x - f[j].x;
				}
			}
			res += f[i].y * num / den;
		}
		return res;
	}

	static boolean doubleEquals(double a, double b) {
		return Math.abs(a - b) / Math.max(1, Math.max(Math.abs(a), Math.abs(b))) < 1e-6;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Point[] f = new Point[n + 1], g = new Point[n + 1];
		for (int i = 0; i <= n; i++) {
			f[i] = new Point(sc.nextInt(), sc.nextInt());
		}
		for (int i = 0; i <= n; i++) {
			g[i] = new Point(sc.nextInt(), sc.nextInt());
		}
		double c = f[0].y - interpolate(f[0].x, g);
		for (int i = 1; i <= n; i++) {
			if (!doubleEquals(interpolate(f[i].x, g) + c, f[i].y)) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
		System.out.printf("%.10f\n", c);
	}
}