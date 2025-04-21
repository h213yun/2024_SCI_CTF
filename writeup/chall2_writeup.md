## Chall 2. Crypto Genius

###  Category: Crypto
---
### Description 
> 안녕하세요. 요청하셨던 2024년 암호만재 투어를 새해 맞이 특가에 예약해드렸습니다.
암호천재를 넘어 암호만재가 되기 위한 여정에 함께하게 되신 것을 축하드립니다. 곧 골든티켓의 비밀번호를 풀어내는 투어가 시작될 예정이니 투어 예약번호를 입력하고 준비해주시길 바랍니다. 자, 이제 손에 넣으면 암호만재가 된다는 전설의 골든티켓을 찾아주세요!
> 

> 암호만재 투어 예약번호: $ nc ctf.h4ck1ngis1y.xyz 1231

### Files

- `password.txt`  
- `publicKey.txt`

---

### Intended Knowledge 
- RSA 암호 알고리즘(textbook-RSA)의 기본적인 원리를 이해하고 있는가

---

### Approach 
- 포트에 접속해보니 문제가 이렇게 뜬다. RSA 키의 길이가 짧다고 한 것을 보아 RSA 암호 알고리즘 문제임을 추론해볼 수 있다.
![image](https://github.com/user-attachments/assets/ee70910a-23d1-447c-812b-c0a11f794e90)
- 암호화된 메세지 C가 17이고, 그것을 복호화한 m의 값을 구해야 하는 것 같다. 힌트로는 나머지가 1일 때 몫도 1이라고 주어졌다. 
<br/><br/>

- 문자를 입력했더니 숫자만 입력가능하다고 한다. 비밀번호는 숫자로만 이루어져있는 것 같다.
![image](https://github.com/user-attachments/assets/3820645e-f0e4-455f-876a-e2a4a0ed55a8)


- 임의로 1000을 입력해보니 다시 시도하라고 했다. 
![image](https://github.com/user-attachments/assets/8676c93e-a92a-4404-995e-c23be7d363dc)
<br/><br/>

- password.txt 를 보니 m을 이진수로 표현한 문자열을 2번 연속으로 쓰고 2024를 이어붙인 것이 비밀번호인듯하다. 
![image](https://github.com/user-attachments/assets/c9042db1-e994-4906-90de-c7a5535fad24)
<br/><br/>

- publicKey.txt 에 따르면 e는 3이고 N은 33이다. 
![image](https://github.com/user-attachments/assets/35f74e87-174a-423d-81e2-157cbe59f1fd)
<br/><br/>

- **N의 숫자가 작아서 두 소수로 쉽게 분해할 수 있다.** 따라서 p와 q는 3, 11이다.  p, q는 서로소이면서 소수이므로 *φ(N) = (p-1)*(q-1) = 2*10 = 20이다.*
    - RSA 알고리즘에서 키의 길이는 N의 크기와 같다. 키가 짧고, e의 수도 작기 때문에 여러 측면으로 보안에 취약하다는 것을 알 수 있다.

- d를 확정짓는 모듈러 연산을 할 때 나머지가 1이어야 한다. 그렇다면 문제 파일에 적혀있던 hint를 사용해 몫이 1임을 알 수 있고 가능한 d값은 7뿐이다.
    - *(e*d) mod φ(N)) = 1*
        
        → *(3*7) mod 20= 1*
        

- 이제 d와 N을 알고 있기 때문에 복호화를 할 수 있다.
    
    *m = c^d mod N
    m = 17^7 mod 33
    m = 410338673 mod 33* → 숫자가 크니까 온라인 모듈러 연산기를 사용하면 편리하다. 
    따라서 m의 값은 8이고, 이진수로 표현하면 **1000**이다.  ~~(암호1000재 ㅎㅎ)~~
    
    → 비밀번호: 100010002024
<br/><br/>

- 비밀번호를 입력하면~ 플래그 획득 성공!
  ![image](https://github.com/user-attachments/assets/44d837a3-790d-4e9f-b180-43f82cc15270)

