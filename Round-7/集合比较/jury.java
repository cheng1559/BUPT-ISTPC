import java.util.HashSet;
import java.util.Scanner;

public class jury {
	public static void main(String[] args) {
		var in = new Scanner(System.in);
		var x = new HashSet<Integer>();
		var y = new HashSet<Integer>();
		int xSize = in.nextInt();
		for (int i = 0; i < xSize; i++) {
			x.add(in.nextInt());
		}
		int ySize = in.nextInt();
		for (int i = 0; i < ySize; i++) {
			y.add(in.nextInt());
		}
		boolean x_is_subset_of_y = true, y_is_subset_of_x = true;
		for (int i : x) {
			if (!y.contains(i)) {
				x_is_subset_of_y = false;
				break;
			}
		}
		for (int i : y) {
			if (!x.contains(i)) {
				y_is_subset_of_x = false;
				break;
			}
		}
		if (x_is_subset_of_y && y_is_subset_of_x) {
			System.out.println("=");
		} else if (x_is_subset_of_y) {
			System.out.println("<");
		} else if (y_is_subset_of_x) {
			System.out.println(">");
		} else {
			System.out.println(".");
		}
	}
}
