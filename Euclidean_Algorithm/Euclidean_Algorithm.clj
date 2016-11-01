(defn GCD [num1 num2]
  (loop [a num1
         b num2]
    (if (= b 0)
      a
      (recur b (mod a b)))))

(GCD 30 105) ;; => 15
(GCD 105 30) ;; => 15
(GCD 2 3);; => 1
(GCD -3 3);; => -3
