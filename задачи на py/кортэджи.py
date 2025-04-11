numbers = tuple(range(1, 7))

participants = ("Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов", "Жабин")
print("фамилия с номером 5: ", participants[4])

print("первый элемент кортеджа с номером 5: ", numbers[4])

anall = f"{participants[4]} {numbers[4]}"
print("обьедененные кортеджи: ", anall)

combined_tuple = participants + numbers

slice_tuple = combined_tuple[1:8]

print("Объединённый кортеж:", combined_tuple)
print("Срез кортежа:", slice_tuple)