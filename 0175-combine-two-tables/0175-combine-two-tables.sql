SELECT FirstName, LastName, City, State
FROM Person
left JOIN Address
  ON Person.PersonId = Address.PersonId;
