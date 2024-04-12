import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score
from sklearn.preprocessing import StandardScaler
from datetime import datetime, timedelta
import pymysql



# Conexión a la base de datos MySQL
conn = pymysql.connect(
    host='localhost',
    user='root',
    password='',
    database='employees'
)

# Obtener datos de la tabla "salary" con la nueva columna "is_current"
salary_query = """
SELECT
    emp_no,
    salary,
    from_date AS salary_from_date,
    to_date AS salary_to_date,
    CASE
        WHEN to_date = '9999-01-01' THEN 1
        ELSE 0
    END AS is_current
FROM
    salaries;
"""

# Obtener datos de la tabla "titles"
titles_query = """
SELECT
    emp_no,
    title,
    from_date AS title_from_date,
    to_date AS title_to_date
FROM
    titles;
"""

# Cargar los datos en DataFrames
salary_df = pd.read_sql(salary_query, conn)
titles_df = pd.read_sql(titles_query, conn)

# Filtrar los salarios actuales (is_current igual a 1)
current_salaries = salary_df[salary_df['is_current'] == 1]

# Calcular la duración del salario actual
current_salaries['duration'] = (datetime.now() - pd.to_datetime(current_salaries['salary_from_date'])).dt.days

# Unir los datos de salario con los datos de título
merged_data = current_salaries.merge(titles_df, on='emp_no')

# Seleccionar las características (features) y la variable objetivo
features = ['duration']
target = 'salary'

# Inicializar un diccionario para almacenar los modelos por título
models_by_title = {}

# Obtener las opciones de títulos y asignar un número a cada título
titulo_options = merged_data['title'].unique()
titulo_dict = {f'{i + 1}': title for i, title in enumerate(titulo_options)}

# Imprimir las opciones de títulos con sus números
print("Opciones de títulos:")
for num, title in titulo_dict.items():
    print(f"{num}: {title}")

# Iterar sobre los títulos únicos y entrenar modelos
for title in titulo_dict.values():
    title_data = merged_data[merged_data['title'] == title]

    # Seleccionar las características y la variable objetivo para el título actual
    X_title = title_data[features]
    y_title = title_data[target]

    # Dividir los datos en conjuntos de entrenamiento y prueba
    X_train, X_test, y_train, y_test = train_test_split(X_title, y_title, test_size=0.2, random_state=42)

    # Escalar las características para modelos sensibles a la escala
    scaler = StandardScaler()
    X_train = scaler.fit_transform(X_train)
    X_test = scaler.transform(X_test)

    # Modelo de Random Forest Regressor por título
    model = RandomForestRegressor(random_state=42)
    model.fit(X_train, y_train)

    # Almacenar el modelo por título
    models_by_title[title] = model



# Solicitar entrada del usuario
while True:
    title_input = input("Ingrese el número correspondiente al título (o escriba 'fin' para salir): ")

    if title_input.lower() == 'fin':
        break

    # Verificar si el número ingresado existe en el diccionario de títulos
    if title_input in titulo_dict:
        # Obtener el título correspondiente al número ingresado
        selected_title = titulo_dict[title_input]

        # Imprimir métricas para el título actual
        print(f'\nReporte para el Título: {selected_title}')

        # Seleccionar las características y la variable objetivo para el título actual
        X_test_title = merged_data[merged_data['title'] == selected_title][features]
        y_test_title = merged_data[merged_data['title'] == selected_title][target]

        # Inicializar y ajustar el escalador (scaler)
        scaler = StandardScaler()
        X_test_title_scaled = scaler.fit_transform(X_test_title)

        # Modelo de Random Forest Regressor
        rf_model = models_by_title[selected_title]  # Utilizar el título directamente como clave

        # Realizar predicción para los datos de prueba
        predictions = rf_model.predict(X_test_title_scaled)

        # Calcular métricas de desempeño
        mse_title = mean_squared_error(y_test_title, predictions)
        mae_title = mean_absolute_error(y_test_title, predictions)
        r2_title = r2_score(y_test_title, predictions)*100

        # Imprimir métricas para el título actual
        print(f'MSE para {selected_title}: {mse_title:.2f}')
        print(f'MAE para {selected_title}: {mae_title:.2f}')
        print(f'R2 para {selected_title}: {r2_title:.2%}')

        # Predicción para el siguiente año
        user_input = pd.DataFrame({'duration': [365]})  # 365 días para el próximo año

        # Escalar la entrada del usuario
        user_input_scaled = scaler.transform(user_input)

        # Realizar predicción para los datos del usuario
        user_prediction = rf_model.predict(user_input_scaled)

        # Imprimir la predicción
        print(f'La estimación del salario para el título {selected_title} para el próximo año es: {user_prediction[0]:.2f}')
    else:
        print("El número ingresado no corresponde a ningún título en la base de datos.")

# Cerrar la conexión a la base de datos
conn.close()

        
        
        
        
        
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


