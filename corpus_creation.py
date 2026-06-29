import pandas as pd

df = pd.read_parquet("train.parquet")

with open("corpus.txt", "w", encoding="utf-8") as f:
    for text in df["text"]:
        f.write(text + "\n")