(define (add digits lst n carry)
    (cond
        [(and (= n 0) (> carry 0)) (append lst (list carry))]
        [(> n 0) 
            (let ([current (+ carry (first digits))])
                (let ([new_digit (modulo current 10)])
                    (let ([new_carry (quotient current 10)])
                        (add (rest digits) (append lst (list new_digit)) (- n 1) new_carry)
                    )
                )
            )
        ]
        [else lst]
    )
)

(define/contract (plus-one digits)
    (-> (listof exact-integer?) (listof exact-integer?))
        (reverse (add (reverse digits) '() (length digits) 1))
)