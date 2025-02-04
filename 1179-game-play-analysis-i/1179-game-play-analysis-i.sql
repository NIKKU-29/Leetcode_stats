Select player_id, min(event_date) As first_login From Activity
Group BY player_id ;