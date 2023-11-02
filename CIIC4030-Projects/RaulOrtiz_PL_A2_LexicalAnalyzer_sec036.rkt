#lang racket

(require parser-tools/lex)
(require (prefix-in : parser-tools/lex-sre))

;;CIIC	4030/ICOM	4036	Programming	Languages
;;Assignment #2

;;Write a Lexical Analyzer in Racket with the following token definitions: 
;;• identifiers: [a-zA-Z]+
;;• delimiters: "("|")"|”[“|”]”
;;• operators: "+"|"*"|”%”
;;• integers: -?[0-9]+
;;• whitespace: [ \n]+
;;As an example of output (your_lexer “2*[6%2]”) should yield
;;( (INT 2)(OP *)(LB)(INT 6)(OP module)(INT 2)(RB) )

;; Author: Raul A Ortiz Rivera sec. 036 #802-18-7733

(define (lexicalAnalyzer L)
  (my_lexer (open-input-string L)))

(define my_lexer
  (lexer
   
;; identifiers
   [(:+ (:or (char-range #\A #\Z) (char-range #\a #\z)))
    
    (cons `(ID , (string->symbol lexeme))
          (my_lexer input-port))]
   
;; delimiters
   [#\( 
    (cons `(LP)
          (my_lexer input-port))]
   [#\)
    (cons  `(RP) 
          (my_lexer input-port))]
   [#\[ 
    (cons `(LB)
          (my_lexer input-port))]
   [#\]  
    (cons `(RB)
          (my_lexer input-port))]
   
;; operators
   [(:or #\+ #\*)
    (cons `(OP ,(string->symbol lexeme))
          (my_lexer input-port))]
   [(:or #\%)
    (cons `(OP module)
          (my_lexer input-port))]
   
;; integers
   [(:: (:? #\-) (:+ (char-range #\0 #\9)))
    
    (cons `(INT ,(string->number lexeme))
      (my_lexer input-port))]

;; whitespace 
   [whitespace  
    (my_lexer input-port)]
   
;;end-of-file   
   [(eof)
    `( )]))

;;Testing
      ;;(lexicalAnalyzer "A a([])*+%1 2 3 ")

;;Expected output
      ;; '((ID A) (ID a) (LP) (LB) (RB) (RP) (OP *) (OP +) (OP module) (INT 1) (INT 2) (INT 3))
