import logging

# NOTE: Move "../explicits.log" to an absolute  path in the config location
logger = logging.getLogger()
logger.setLevel(logging.INFO)

file_handler = logging.FileHandler('../explicits.log')
console_handler = logging.StreamHandler()

formatter = logging.Formatter('%(asctime)s - %(filename)s - %(funcName)s - Line: %(lineno)d - %(levelname)s - %(message)s')

file_handler.setFormatter(formatter)
console_handler.setFormatter(formatter)

console_handler.setLevel(logging.INFO)

logger.addHandler(file_handler)
logger.addHandler(console_handler)
