from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart
import smtplib
import os

file = open("text.txt", 'r')
texty = file.read()

smtp = smtplib.SMTP('smtp.gmail.com', 587)
smtp.ehlo()
smtp.starttls()
smtp.login('sahaniabhishek2402@gmail.com', 'wxinfqozkokyghje')

msg = MIMEMultipart()
msg['Subject'] = "Challenges completed"

msg.attach(MIMEText(texty))

img_data = open("sample.jpg", 'rb').read()
msg.attach(MIMEImage(img_data,
                     name=os.path.basename("sample.jpg")))


to = ["developerstudentcircuit@gmail.com"]

smtp.sendmail(from_addr="sahaniabhishek2402@gmail.com",
              to_addrs=to, msg=msg.as_string())

smtp.quit()