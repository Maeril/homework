# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    the_bank.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myener <myener@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 21:17:42 by myener            #+#    #+#              #
#    Updated: 2020/07/05 22:06:43 by myener           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

class Account(object):

	ID_COUNT = 1

	def __init__(self, name, **kwargs):
		self.id = self.ID_COUNT
		self.name = name
		self.__dict__.update(kwargs)
		if hasattr(self, 'value'):
			self.value = 0
		Account.ID_COUNT += 1

	def transfer(self, amount):
		self.value += amount

	def corruption_check(self):
		if len(dir(self)) % 2 == 0:
			return True
		if (any(i.startswith('b') for i in dir(self))):
			return True
		if not (hasattr(self, "addr") or hasattr(self, "zip")):
			return True
		if not hasattr(self, "name") or not hasattr(self, "id") or not hasattr(self, "value"):
			return True
		return False

class Bank(object):
	"""The bank"""
	def __init__(self):
		self.account = []

	def add(self, account):
		self.account.append(account)

	def getacc_name(self, name):
		for acc in self.account:
			if acc.name == name:
				return acc
		return None

	def getacc_id(self, id):
		if id < 0 or id >= len(self.account):
			return None
		return self.account[id]

	def transfer(self, origin, dest, amount):
		"""
			@origin:  int(id) or str(name) of the first account
			@dest:    int(id) or str(name) of the destination account
			@amount:  float(amount) amount to transfer
			@return         True if success, False if an error occured
		"""
		if isinstance(origin, int):
			origin = getacc_name(origin)
		if isinstance(origin, int):
			origin = getacc_id(origin)
		if isinstance(origin, int):
			dest = getacc_name(dest)
		if isinstance(origin, int):
			dest = getacc_id(dest)

		if not isinstance(origin, Account) or not isinstance(dest, Account):
			return False
		if not isinstance(amount, float):
			return False
		if origin.corruption_check() is True or dest.corruption_check() is True:
			return False
		if amount < 0 or amount > origin.value:
			return False
		origin.transfert(-amount)
		dest.transfert(+amount)
		return True

	def fix_account(self, account):
		"""
			fix the corrupted account
			@account: int(id) or str(name) of the account
			@return         True if success, False if an error occured
		"""
		if isinstance(account, int):
			account = self.getacc_id(account)
		elif isinstance(account, str):
			account = self.getacc_name(account)
		if not isinstance(account, Account):
			return False

		if not account.corruption_check():
			return True

		try:
			if any(i.startswith('b') for i in dir(account)):
					delattr(account, i)
			if not (hasattr(account, "addr") or hasattr(account, "zip")):
				setattr(account, "addr", input("Please enter your address:\n>> "))
			if not hasattr(account, "name"):
				setattr(account, "name", input("Please enter your name:\n>> "))
			if not hasattr(account, "id"):
				setattr(account, "id", self.account.index(account))
			if not hasattr(account, "value"):
				setattr(account, "value", 0)
			if len(dir(account)) % 2 == 0:
				setattr(account, "fixed", True)
			return True
		except:
			return False