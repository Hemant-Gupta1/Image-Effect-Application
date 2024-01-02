package com.iiitb.imageEffectApplication.service;

import com.iiitb.imageEffectApplication.model.LogModel;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class LoggingService {
    // ArrayList to store logs
    private ArrayList<LogModel> logs = new ArrayList<LogModel>();

    // Method to add a new log entry
    public void addLog(String fileName, String effectName, String optionValues) {
        // Get current date and time
        LocalDateTime dateTime = LocalDateTime.now();
        // Format date and time
        DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String formattedDateTime = dateTime.format(dateTimeFormatter);
        // Create a new log entry
        LogModel new_log = new LogModel(formattedDateTime, fileName, effectName, optionValues);
        // Add the log to the list
        this.logs.add(new_log);
    }

    // Method to retrieve all logs
    public List<LogModel> getAllLogs() {
        return logs;
    }

    // Method to get logs filtered by effect name
    public List<LogModel> getLogsByEffect(String effectName) {
        List<LogModel> logsByEffect = new ArrayList<LogModel>();
        // Iterate through logs and filter by effect name
        for (LogModel log : logs) {
            if (log.getEffectName().equals(effectName)) {
                logsByEffect.add(log);
            }
        }
        return logsByEffect;
    }

    // Method to clear all logs
    public void clearLogs() {
        logs.clear();
    }

    // Method to get logs between two timestamps
    public List<LogModel> getLogsBetweenTimestamps(LocalDateTime startTime, LocalDateTime endTime) {
        List<LogModel> logsWithinTimestamps = new ArrayList<>();
        // Iterate through logs and filter by timestamps
        for (LogModel log : logs) {
            String logTimestamp = log.getTimestamp();
            DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            LocalDateTime parsedDateTime = LocalDateTime.parse(logTimestamp, dateTimeFormatter);
            // Check if log timestamp is within the specified range
            if (parsedDateTime.isAfter(startTime) && parsedDateTime.isBefore(endTime)) {
                logsWithinTimestamps.add(log);
            }
        }
        return logsWithinTimestamps;
    }
}