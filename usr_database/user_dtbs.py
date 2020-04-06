users = []
class user:
	def __init__(self,username,login_id,password,age):
		self.username = username
		self.login_id = login_id
		self.password = password
		self.age      = age
while True:
    print("============ User Database Management System ============\n")
    print("\t1.  Add Record")
    print("\t2.  Delete Record")
    print("\t3.  Modify Record")
    print("\t4.  List Record")
    print("\t5.  Exit\n\n")
    choice = int(input("\tSelect your choice ==> "))
    if choice == 1:
	    uname = input("Enter username: ")
	    _id = input("Enter loginid: ")
	    passwd =input("enter password: ")
	    age = input("enter age: ")
	    user(uname,_id,passwd,age)
	    users.append(user)
    elif choice ==4:
	    for u in users:
		    print(f"{u.username} : {u.login_id} : {u.password} : {u.age}")
    else:
	    exit()

