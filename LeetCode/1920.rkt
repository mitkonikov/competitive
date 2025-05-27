(define/contract (build-array nums)
  (-> (listof exact-integer?) (listof exact-integer?))
    (map (lambda (x) (list-ref nums x)) nums)
  )