class MySqlDb {
	public:
		class Result {
			public:
				string get(int row, int col);	
			protected:
				friend class MySqlDb;
				void *result;
		};
		MySqlDb(const char *host, const char *username, const char *password, int port = 3306);
		void query(const string& sql);
		Result query(const string& sql);
};
