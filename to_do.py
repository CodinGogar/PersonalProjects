from fastapi import FastAPI
#for making the request body
from pydantic import BaseModel
from typing import List

app = FastAPI()

#to store tasks
task_bank = []

@app.get("/")
def welcome():
    return {"message": "Welcome to the to do list API!"}

#request body
class task_request(BaseModel):
    task: List[str]

#endpoint to create tasks
@app.post("/create_tasks")
async def create_task(tasks:task_request):
    task_bank.append(tasks)
    return {"message": f"Task created: {tasks}"}

#display all tasks
@app.get("/show_tasks")
def show():
    if len(task_bank) == 0:
        return {"message": "No tasks available!"}
    else:
        for i in task_bank:
            return{i}
#update a task
@app.put("/update_task")
def update_task(task_id: int, new_task: str):
    #find the task to update
    for i in task_bank:
        if task_bank.index(i)+1 == task_id:
            #update the task
            task_bank[task_id] = new_task
            return{"message":f"task {task_id} updated to {new_task}"}
        
    message =  f"task {task_id} not found. Adding new task {new_task}"
    task_bank.append(new_task)
    return{message}
    
#delete a task
@app.delete("/delete_task/{task_id}")
def delete_task(task_id: int):
    task_bank.remove(task_bank.index(task_id))
    return{"message":f"{task_bank[task_id] } has been deleted"}