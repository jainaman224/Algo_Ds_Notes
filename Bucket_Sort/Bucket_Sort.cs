using System;
using System.Collections.Generic;

namespace bucketsort
{
    class Program
    {
        /// Gets maximal value in the given input.
        static int GetMax(int[] array)
        {   
            int maxval = 0;

            for(int i = 0; i < array.Length; i++)
            {
                if (array[i] > maxval)
                {
                    maxval = array[i];
                }
            }

            return maxval;
        }

        /// Does a BucketSort for given input with n buckets.
        static int[] BucketSort(int[] input, int bucketcount)
        {
            int[] sorted = null;
            int inputsize = input.Length;
            List<int>[] buckets = new List<int>[bucketcount];
            int bucketindex = 0;
            int v = 0;
            int max = GetMax(input);

            // Create <bucketcount> buckets and put them into the bucket container.
            for (int i = 0; i < bucketcount; i++)
            {
                buckets[i] = new List<int>();
            }

            for (int i = 0; i < inputsize; i++)
            {
                // Calculate the bucketindex for each value in the given input.
                bucketindex = (bucketcount * input[i] / (max + 1));

                buckets[bucketindex].Add(input[i]);
            }

            // Sort each bucket that has been created in ascending order.
            foreach (List<int> bucket in buckets)
            {
                bucket.Sort();
            }

            sorted = new int[inputsize];

            // Put the elements of the buckets into the result array.
            for (int i = 0; i < buckets.Length; i++)
            {
                for (int j = 0; j < buckets[i].Count; j++)
                {
                    sorted[v++] = buckets[i][j];
                }
            }

            return sorted;
        }

        /// Do BucketSort.
        static void Main(string[] args)
        {
            int buckets = 5;
            int inputlength = 0;
            int number = 0;
            int[] input = null;

            if (args.Length == 0)
            {
                Console.WriteLine("No Arguments given");

                return;
            }
            
            inputlength = args.Length;

            input = new int [inputlength];

            for(int i = 0; i < args.Length; i++)
            {
                if (!int.TryParse(args[i], out number))
                {
                    Console.WriteLine(string.Format("Argument at index {0} not valid", i));

                    return;
                }

                input[i] = number;
            }

            foreach(int i in BucketSort(input, buckets))
            {
                Console.Write(i.ToString() + " ");
            }
            Console.Write('\n');
        }
    }
}

/*
 * Input: [2, 16, 3, 82, 7, 132, 5200, 6, 4, 10000, 8, 9]
 *
 * Buckets:
 * [0] = [2, 3, 4, 6, 7, 8, 9, 16, 82, 132]
 * [1] = []
 * [2] = [5200]
 * [3] = []
 * [4] = [10000]
 *
 * Output: [2, 3, 4, 6, 7, 8, 9, 16, 82, 132, 5200, 10000]
 */
