## Chall 1. Do you like strawberries? 

###  Category: Forensics / Steganography  
---
### Files

- `ddalki.png`  
- `hint.txt`

---

### Intended Knowledge / Tools

- 스테가노그래피 개념  
- `binwalk`, 압축 해제 도구 활용법  
- 이미지 분석을 통한 비밀번호 추론

---
<br/>

### Approach
- 겉보기에는 평범한 .png 파일이다. 
![image](https://github.com/user-attachments/assets/ba411a06-5e7b-468c-9072-97c25e3ad285)
<br/><br/>

- hint 파일을 열어보니 딸기 안에 뭔가 들어있다고 한다. 딸기 이미지 안에 어떤 것을 숨겨두었다는 뜻이므로 스테가노그래피 문제임을 추론해볼 수 있겠다. 
![image](https://github.com/user-attachments/assets/8b6da111-a533-4a49-8ae1-6cad61e3c69a)
<br/><br/>

- 여러 가지 툴을 사용해볼 수 있겠지만 binwalk -e ddalki.png 명령어 입력해서 분석해보자. 
![image](https://github.com/user-attachments/assets/8946e873-d84c-4626-b4c1-e75169da6867)

- how_many_strawberries_are_there 라는 이름을 가진 .zip 파일이 존재하고, 그 안에 동명의 텍스트 파일과 flag.docx 문서파일이 있다.  

<br/><br/>

- binwalk를 수행하면 추출된 파일 생성된다. 새로 생성된 폴더를 들어가보자. 
![image](https://github.com/user-attachments/assets/a3423863-ab88-4dae-b1d6-21126689fbba)
- 그 안에 있는 how_many_strawberries_are_there 파일을 눌러보니 파일 이름에 답하라는 howto.txt 텍스트 파일과 flag.docx 문서 파일이 있다. 그리고 문서 파일에는 비밀번호가 걸려있다.

<br/><br/>

- 파일명에 답하라고 쓰여있다. 
![image](https://github.com/user-attachments/assets/21884313-5030-4683-b2c4-f87866a92be4)

![image](https://github.com/user-attachments/assets/8f595cdc-e331-42ec-ad95-785049dc5f4d)
<br/><br/>

-  사진 속에 딸기는 10개가 있으므로 비밀번호에 10을 입력해보자.
-  플래그 획득 완료!
![image](https://github.com/user-attachments/assets/ca80828c-a271-4bbb-85b5-c405aa272e95)

---
### Reference 
https://cyberpj.medium.com/how-create-steganography-challenges-13-e32ce96aa7df
