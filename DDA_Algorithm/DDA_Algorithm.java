/*
    author: kunal-kushwaha
    date: 25-03-2019
*/

import java.awt.*;
import javax.swing.JFrame;
import java.lang.*;
import java.util.Scanner;

public class DDA_Algorithm extends Canvas {

  static int x0, y0, x1, y1;

  DDA_Algorithm(int x0, int y0, int x1, int y1) {
    // initialising coordinates
    this.x0 = x0;
    this.y0 = y0;
    this.x1 = x1;
    this.y1 = y1;
  }
  public void paint(Graphics graphics) {
    int disx, disy;
    float X, Y, x, y, counter;
    disy = y1 - y0;
    disx = x1 - x0;
    graphics.fillOval(x0, y0, 10, 10);
    if (disy > disx) {
      counter = Math.abs(disy);
    } else {
      counter = Math.abs(disx);
    }

    x = x0;
    X = disx / counter;
    y = y0;
    Y = disy / counter;
    while (counter-- != 0) {
      x = x + X;
      y = y + Y;
      graphics.fillOval(Math.round(x), Math.round(y), 10, 10);
    }
  }

  public static void main(String args[]) {

    Scanner sc = new Scanner(System.in);

    System.out.println("Enter first coordinates (x0,y0) : ");
    int x0 = sc.nextInt();
    int y0 = sc.nextInt();
    System.out.println("Enter last coordinates (x1,y1) : ");
    int x1 = sc.nextInt();
    int y1 = sc.nextInt();

    DDA_Algorithm dda_algorithm = new DDA_Algorithm(x0, y0, x1, y1);

    JFrame frame = new JFrame();
    frame.add(dda_algorithm);
    frame.setSize(1000, 1000);
    frame.setVisible(true);
  }
}

/*
  OUTPUT :

  Enter first coordinates (x0,y0) :
  45 30
  Enter last coordinates (x1,y1) :
  550 620

  output : https://ibb.co/Vt3jR8c

*/
