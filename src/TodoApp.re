type item = {
  title: string,
  completed: bool,
};

type state = {items: list(item)};

type action =
  | AddItem;

let component = ReasonReact.reducerComponent("TodoApp");

let str = ReasonReact.stringToElement;

let newItem = () => {title: "Click a button", completed: true};

let make = _children => {
  ...component,
  initialState: () => {
    items: [{title: "Write some OCamL Programming", completed: false}],
  },
  reducer: (action, {items}) =>
    switch (action) {
    | AddItem => ReasonReact.Update({items: [newItem(), ...items]})
    },
  render: ({state: {items}, reduce}) => {
    let numItems = List.length(items);
    <div className="app">
      <div className="title"> (str("What to do")) </div>
      <button onClick=(reduce((_evt) => AddItem))>
        (str("Add something"))
      </button>
      <div className="items"> (str("Nothing")) </div>
      <div className="footer">
        (str(string_of_int(numItems) ++ " items"))
      </div>
    </div>;
  },
};