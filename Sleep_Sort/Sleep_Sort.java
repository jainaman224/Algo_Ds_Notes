/**
 * Created by jude on 21/10/16.
 */
public class sleepSort {
    private static int[] elements = {3, 6, 3, 9, 10, 8, 2};

    public static void main(String[] args)
    {
        sleepSortMethod(elements);
    }

    private static void sleepSortMethod(int[] elements) {
        for(int element: elements)
        {
            Thread thread = new Thread(new sleepSortThread(element));
            thread.start();
        }
    }

    private static class sleepSortThread implements Runnable {
        int element;
        public sleepSortThread(int element) {
            this.element = element;
        }

        @Override
        public void run() {
            try
            {
                Thread.sleep(element);
                System.out.println(element);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

/* Output
        2
        3
        3
        6
        8
        9
        10
*/
