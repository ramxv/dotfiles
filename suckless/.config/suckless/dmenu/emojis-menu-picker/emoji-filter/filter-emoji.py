import pandas as pd

emojiDB = pd.read_csv("./emojis-db.csv")

emogiDF = pd.DataFrame(emojiDB).drop_duplicates()

filteredEmojis = emogiDF[["Emoji", "Description"]]

filteredEmojis.to_csv("filteredEmojiDB.csv", index=False)
