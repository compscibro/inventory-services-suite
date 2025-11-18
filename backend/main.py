from fastapi import FastAPI, HTTPException

# fastapi tutorial: https://youtu.be/iWS9ogMPOI0?si=s97IpGNbOL58ALFZ

# uvicorn backend.main:app --reload
# http://127.0.0.1:8000

app = FastAPI()

items = []

# @app.get("/") # when someone visits this,
# def root(): # this function is going to get called
#     return {"Hello" : "World"}

@app.post("/items")
def create_item(item: str):
    items.append(item)
    return items

@app.get("/items")
def list_items(limit: int = 10):
    return items[0:limit]

@app.get("/items/{item_id}")
def get_item(item_id: int) -> str:
    if item_id < len(items):
        return items[item_id]
    else:
        raise HTTPException(status_code=404, detail="Item not found")
